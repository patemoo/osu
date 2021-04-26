const error = require('../errors');
const { boatsRef, loadsRef, slipsRef } = require('../database');
const {
    viewBoat,
} = require('../model/boats');
const {
    assignLoad,
    createLoad,
    DeleteLoad,
    validateLoadParams,
    viewAllLoads,
    viewLoad,
} = require('../model/loads');

const controller = {};

/* V2 */

// Create a Load
controller.createLoad = async (req, res) => {
    const params = req.body;
    if (validateLoadParams(params)) {
        const loadId = await createLoad(params, loadsRef);
        const load = await viewLoad(loadId, loadsRef);
        res.status(201).json(load)
    } else {
        res.status(400).json(error.badRequestError_load);
    }
};

// View a Load
// params: id
controller.viewLoad = async (req, res) => {
    const loadId = req.params.id;
    const load = await viewLoad(loadId, loadsRef);
    if (!load.id) {
        res.status(404).json(error.notFoundError_load);
    } else {
        res.status(200).json(load);
    }
};

// View all Loads
controller.viewAllLoads = async (_req, res) => {
    // todo:
};

// Delete  a Load
// params: id
controller.deleteLoad = async (req, res) => {
    const loadId = req.params.id;
    // todo: 
};

// Assign a Load to a Boat
// params: boat_id, load_id
controller.assignLoad = async (req, res) => {
    const boatId = req.params.boat_id;
    const loadId = req.params.load_id;
    const boat = await viewBoat(boatId, boatsRef);
    if (!boat.id) {
        res.status(404).json(error.notFoundError_boat);
        return;
    }
    const load = await viewLoad(loadId, loadsRef);
    if (!load.id) {
        res.status(404).json(error.notFoundError_load);
        return;
    }
    if (load.carrier) {
        res.status(400).json(error.alreadyAssigned_load);
        return;
    }
    await assignLoad(boatId, loadId, boatsRef, loadsRef);
    res.status(204).end();

}

// View all Loads for a Boat
// params: boat_id
controller.viewAllLoadsForBoat = async (req, res) => {
    const boatId = req.params.boat_id;
    // todo: 
};

/**
 * Module exports.
 * @public
 */

 module.exports = controller;