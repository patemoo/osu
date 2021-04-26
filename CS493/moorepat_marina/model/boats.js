const { baseUrl, log } = require('../util');
const { boatsRef, getBoat, getBoatData, getBoatRef } = require('../database');

const boats = {};

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

// Returns true if valid, else returns false.
boats.validateBoatParams = (_params) => {
    return _params && _params.name && _params.type && _params.length;
};

// Creates a boat; Returns boat id.
boats.createBoat = async (_params) => {
    try {
        const newBoatRes = await boatsRef.add(_params);
        return newBoatRes.id;
    } catch(e) {
        log("Create Boat Error: ", e);
    }
};

// Returns a boat if it exists.
boats.getBoat = async (_id) => {
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
boats.getAllBoats = async () => {
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
boats.updateBoat = async (_id, _params) => {
    try {
        return await boatsRef.doc(String(_id)).set(_params);
    } catch(e) {
        log("Update Boat Error: ", e);
    }
};

// Deletes a boat; Returns write result.
boats.deleteBoat = async (_id) => {
    try {
        return await boatsRef.doc(String(_id)).delete();
    } catch(e) {
        log("Delete Boat Error: ", e);
    }
};

/* V2 */

// Returns a boat including id and self (url).
const boatRefToBoatV2 = (_boat) => {
    const boatId = _boat.id;
    const boatData = _boat.data();
    boatData.loads = boatData.loads ? boatData.loads.map(loadId => ({
        id: loadId,
        self: `${baseUrl}/v2/loads/${loadId}`,
    })) : null;
    const boat = {
        id: boatId,
        ...boatData,
        self: `${baseUrl}/v2/boats/${boatId}`,
    }
    return boat;
};

// View boat
boats.viewBoat = async (_id) => {
    try {
        const boat = await getBoat(_id);
        if (!boat.exists) {
            log(`A boat with an id of ${_id} does not exist.`);
            return {};
        } else {
            return boatRefToBoatV2(boat);
        }
    } catch(e) {
        log("Get Boat Error: ", e);
    }
};

// View all boats
boats.viewAllBoats = async () => {
    try {
        const allBoats = [];
        const snapshot = await boatsRef.get();
        snapshot.forEach(boatRef => {
            allBoats.push(boatRefToBoatV2(boatRef));
        });
        return allBoats;
    } catch(e) {
        log("Get all Boats Error: ", e);
    }
};

// Deletes a boat; Returns write result.
boats.deleteBoatV2 = async (_boatId) => {
    try {
        const boatRef = getBoatRef(_boatId);
        const boatData = await getBoatData(_boatId);
        const loads = boatData.loads;
        if (loads) {
            loads.map(loadId => loadId);
        }
        return await boatRef.delete();
    } catch(e) {
        log("Delete Boat Error: ", e);
    }
};

/**
 * Module exports.
 * @public
 */

 module.exports = boats;