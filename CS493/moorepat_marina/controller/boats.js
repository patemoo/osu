const error = require('../errors');

const {
    createBoat,
    deleteBoat,
    deleteBoatV2,
    getBoat,
    getAllBoats,
    updateBoat,
    validateBoatParams,
    viewBoat,
    viewAllBoats,
} = require('../model/boats');

const controller = {};

// Create a Boat
controller.createBoat = async (req, res) => {
    const params = req.body;
    if (validateBoatParams(params)) {
        const boatId = await createBoat(params);
        const boat = await getBoat(boatId);
        res.status(201).json(boat);
    } else {
        res.status(400).json(error.badRequestError_boat);
    }
};

// Get a Boat
controller.getBoat = async (req, res) => {
    const boatId = req.params.id;
    if (boatId) {
        const boat = await getBoat(boatId);
        if (!boat.id) {
            res.status(404).json(error.notFoundError_boat);
        } else {
            res.status(200).json(boat);
        }
    }
};

// List all Boats
controller.getAllBoats = async (_req, res) => {
    const boats = await getAllBoats();
    res.status(200).json(boats);
};

// Edit a Boat
controller.updateBoat = async (req, res) => {
    const boatId = req.params.id;
    const boatParams = req.body;
    if (validateBoatParams(boatParams)) {
        // First check if the boat exists.
        const boatToUpdate = await getBoat(boatId);
        if (!boatToUpdate.id) {
            res.status(404).json(error.notFoundError_boat);
        } else {
            // Then update boat data.
            const result = await updateBoat(boatId, boatParams);
            if (result) {
                const updatedBoat = await getBoat(boatId);
                res.status(200).json(updatedBoat);
            }
        }
    } else {
        res.status(400).json(error.badRequestError_boat);
    }
};

// Delete a Boat
controller.deleteBoat =  async (req, res) => {
    const boatId = req.params.id;
    // First check if the boat exists.
    const boatToDelete = await getBoat(boatId);
    if (!boatToDelete.id) {
        res.status(404).json(error.notFoundError_boat);
    } else {
        // Then delete boat.
        const result = await deleteBoat(boatId);
        if (result) {
            res.status(204).end();
        }
    }
};

/* V2 */

// Create a Boat v2
controller.createBoatV2 = async (req, res) => {
    const params = req.body;
    params.loads = null;
    if (validateBoatParams(params)) {
        const boatId = await createBoat(params);
        const boat = await viewBoat(boatId);
        res.status(201).json(boat);
    } else {
        res.status(400).json(error.badRequestError_boat);
    }
};

// Delete a Boat
controller.deleteBoatV2 =  async (req, res) => {
    const boatId = req.params.id;
    // First check if the boat exists.
    const boatToDelete = await viewBoat(boatId);
    if (!boatToDelete.id) {
        res.status(404).json(error.notFoundError_boat);
    } else {
        // Then delete boat.
        const result = await deleteBoatV2(boatId);
        if (result) {
            res.status(204).end();
        }
    }
};

// View a Boat
controller.viewBoat = async (req, res) => {
    const boatId = req.params.id;
    if (boatId) {
        const boat = await viewBoat(boatId);
        if (!boat.id) {
            res.status(404).json(error.notFoundError_boat);
        } else {
            res.status(200).json(boat);
        }
    }
};

// View all Boats
// todo: pagination, 3 boats per page, next link.
controller.viewAllBoats = async (_req, res) => {
    const boats = await viewAllBoats();
    res.status(200).json(boats);
};

/**
 * Module exports.
 * @public
 */

 module.exports = controller;