const express = require('express');
const app = express();

const Firestore = require('@google-cloud/firestore');
const bodyParser = require('body-parser');

const db = new Firestore({
    projectId: 'corded-imagery-309502',
    keyFilename: process.env.GOOGLE_APPLICATION_CREDENTIALS,
});

const router = express.Router();

const isDevEnv = process.env.NODE_ENV == "development";
const baseUrl = isDevEnv ? "http://localhost:8080" : "https://corded-imagery-309502.uk.r.appspot.com";

const boatsRef = db.collection('boats');
const slipsRef = db.collection('slips');

app.use(bodyParser.json());

/* ------------- Begin Model Functions ------------- */

// Log:

const log = (_message) => {
    if (isDevEnv) {
        console.log(_message);
    }
} 


// Errors:

const badRequestError_boat = {
    Error: "The request object is missing at least one of the required attributes"
};

const badRequestError_slip = {
    Error: "The request object is missing the required number"
};

const notFoundError_boat = {
    Error: `No boat with this boat_id exists`
};

const notFoundError_slip = {
    Error: "No slip with this slip_id exists"
};

const notFoundError_slip_and_or_boat = {
    Error: "The specified boat and/or slip does not exist"
};

const notFoundError_boat_not_at_slip = {
    Error: "No boat with this boat_id is at the slip with this slip_id"
}

const notEmptyError_slip = {
    Error: "The slip is not empty"
};

// Boats:

// Returns true if valid, else returns false.
const validateBoatParams = (_params) => {
    return _params && _params.name && _params.type && _params.length;
};

// Returns a boat including id and self (url).
const boatRefToBoat = (_boatRef) => {
    const boatId = _boatRef.id;
    const boatData = {
        id: boatId,
        ..._boatRef.data(),
        self: `${baseUrl}/boats/${boatId}`,
    }
    return boatData;
};

// Creates a boat; Returns boat id.
const createBoat = async (_params) => {
    try {
        const newBoatRes = await boatsRef.add(_params);
        return newBoatRes.id;
    } catch(e) {
        log("Create Boat Error: ", e);
    }
};

// Returns a boat if it exists.
const getBoat = async (_id) => {
    try {
        const boatRef = await boatsRef.doc(String(_id)).get();
        if (!boatRef.exists) {
            log(`A boat with an id of ${_id} does not exist.`);
            return {};
        } else {
            return boatRefToBoat(boatRef);
        }
    } catch(e) {
        log("Get Boat Error: ", e);
    }
};

// Returns all boats.
const getAllBoats = async () => {
    try {
        const allBoats = [];
        const snapshot = await boatsRef.get();
        snapshot.forEach(boatRef => {
            allBoats.push(boatRefToBoat(boatRef));
        });
        return allBoats;
    } catch(e) {
        log("Get all Boats Error: ", e);
    }
};

// Updates boat data; Returns write result
const updateBoat = async (_id, _params) => {
    try {
        return await boatsRef.doc(String(_id)).set(_params);
    } catch(e) {
        log("Update Boat Error: ", e);
    }
};

// Deletes a boat; Returns write result.
const deleteBoat = async (_id) => {
    try {
        return await boatsRef.doc(String(_id)).delete();
    } catch(e) {
        log("Delete Boat Error: ", e);
    }
}


// Slips:

// Returns true if valid, else returns false.
const validateSlipParams = (_params) => {
    return _params && _params.number;
}

// Returns a slip including id and self (url) .
const slipRefToSlip = (_slipRef) => {
    const slipId = _slipRef.id;
    const slipData = {
        id: slipId,
        current_boat: null,
        ..._slipRef.data(),
        self: `${baseUrl}/slips/${slipId}`,
    }
    return slipData;
};

// Creates a slip; Returns slip id.
const createSlip = async (_params) => {
    try {
        const newSlipRes = await slipsRef.add(_params);
        return newSlipRes.id;
    } catch(e) {
        log("Create Slip Error: ", e);
    }
};

// Returns a slip if it exists.
const getSlip = async (_id) => {
    try {
        const slipRef = await slipsRef.doc(String(_id)).get();
        if (!slipRef.exists) {
            log(`A slip with an id of ${_id} does not exist.`);
            return {};
        } else {
            return slipRefToSlip(slipRef);
        }
    } catch(e) {
        log("Get Slip Error: ", e);
    }
};

// Returns all slips.
const getAllSlips = async () => {
    try {
        const allSlips = [];
        const snapshot = await slipsRef.get();
        snapshot.forEach(slipRef => {
            allSlips.push(slipRefToSlip(slipRef));
        });
        return allSlips;
    } catch(e) {
        log("Get all Slips Error: ", e);
    }
};

// Deletes a slip; Returns write result.
const deleteSlip = async (_id) => {
    try {
        return await slipsRef.doc(String(_id)).delete();
    } catch(e) {
        log("Delete Slip Error: ", e);
    }
};

// Adds a Boat to a Slip.
const boatToSlip = async (_slipId, _boatId) => {
    try {
        return await slipsRef.doc(String(_slipId)).update({
            "current_boat": String(_boatId),
        });
    } catch(e) {
        log("Boat Arrives Error: ", e);
    }
};

// Removes a Boat from a Slip.
const boatToSea = async (_slipId, _boatId) => {
    try {
        return await slipsRef.doc(String(_slipId)).update({
            "current_boat": null,
        });
    } catch(e) {
        log("Boat Departs Error: ", e);
    }
}


/* ------------- End Model Functions ------------- */

/* ------------- Begin Controller Functions ------------- */

router.get('/env', (req, res) => {
    res.status(200).json({"NODE_ENV": process.env.NODE_ENV});
});

// Create a Boat
router.post('/boats', async (req, res) => {
    const params = req.body;
    if (validateBoatParams(params)) {
        const boatId = await createBoat(params);
        const boat = await getBoat(boatId);
        res.status(201).json(boat);
    } else {
        res.status(400).json(badRequestError_boat);
    }
});

// Get a Boat
router.get('/boats/:id', async (req, res) => {
    const boatId = req.params.id;
    if (boatId) {
        const boat = await getBoat(boatId);
        if (!boat.id) {
            res.status(404).json(notFoundError_boat);
        } else {
            res.status(200).json(boat);
        }
    }
});

// List all Boats
router.get('/boats', async (_req, res) => {
    const boats = await getAllBoats();
    res.status(200).json(boats);
});

// Edit a Boat
router.patch('/boats/:id', async (req, res) => {
    const boatId = req.params.id;
    const boatParams = req.body;
    if (validateBoatParams(boatParams)) {
        // First check if the boat exists.
        const boatToUpdate = await getBoat(boatId);
        if (!boatToUpdate.id) {
            res.status(404).json(notFoundError_boat);
        } else {
            // Then update boat data.
            const result = await updateBoat(boatId, boatParams);
            if (result) {
                const updatedBoat = await getBoat(boatId);
                res.status(200).json(updatedBoat);
            }
        }
    } else {
        res.status(400).json(badRequestError_boat);
    }
});

// Delete a Boat
router.delete('/boats/:id', async (req, res) => {
    const boatId = req.params.id;
    // First check if the boat exists.
    const boatToDelete = await getBoat(boatId);
    if (!boatToDelete.id) {
        res.status(404).json(notFoundError_boat);
    } else {
        // Then delete boat.
        const result = await deleteBoat(boatId);
        if (result) {
            res.status(204).end();
        }
    }
});


// Create a Slip
router.post('/slips', async (req, res) => {
    const params = req.body;
    if (validateSlipParams(params)) {
        const slipId = await createSlip(params);
        const slip = await getSlip(slipId);
        res.status(201).json(slip);
    } else {
        res.status(400).json(badRequestError_slip);
    }
});

// Get a Slip
router.get('/slips/:id', async (req, res) => {
    const slipId = req.params.id;
    if (slipId) {
        const slip = await getSlip(slipId);
        if (!slip.id) {
            res.status(404).json(notFoundError_slip);
        } else {
            res.status(200).json(slip);
        }
    }
});

// List all Slips
router.get('/slips', async (_req, res) => {
    const slips = await getAllSlips();
    res.status(200).json(slips);
});

// Boat Arrives at a Slip
router.put('/slips/:slip_id/:boat_id', async (req, res) => {
    const slipId = req.params.slip_id;
    const boatId = req.params.boat_id;

    // Check if the slip and boat exists.
    const slip = await getSlip(slipId);
    const boat = await getBoat(boatId);
    if (!slip.id || !boat.id) {
        res.status(404).json(notFoundError_slip_and_or_boat);
    }
    // Check for current boat at slip.
    if (slip.current_boat) {
        res.status(403).json(notEmptyError_slip);
    }

    const result = await boatToSlip(slipId, boatId);
    if (result) {
        res.status(204).end();
    }
});

// Boat Departs a Slip
router.delete('/slips/:slip_id/:boat_id', async (req, res) => {
    const slipId = req.params.slip_id;
    const boatId = req.params.boat_id;

    // Check if the boat is at the slip.
    const slip = await getSlip(slipId);
    if (slip.current_boat != boatId) {
        res.status(404).json(notFoundError_boat_not_at_slip);
    }

    const result = await boatToSea(slipId, boatId);
    if (result) {
        res.status(204).end();
    }
});

// Delete a Slip
router.delete('/slips/:id', async (req, res) => {
    const slipId = req.params.id;

    // First check if the slip exists.
    const slipToDelete = await getSlip(slipId);
    if (!slipToDelete.id) {
        res.status(404).json(notFoundError_slip);
    } else {
        // Then delete slip.
        const result = await deleteSlip(slipId);
        if (result) {
            res.status(204).end();
        }
    }
});

/* ------------- End Controller Functions ------------- */

app.use('/', router);

// Listen to the App Engine-specified port, or 8080 otherwise
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
  log(`Server listening on port ${PORT}...`);
});
