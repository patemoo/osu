const error = require('../errors');
const { boatsRef, slipsRef } = require('../database');

const {
    getBoat,
} = require('../model/boats');

const {
    validateSlipParams,
    createSlip,
    getSlip,
    getAllSlips,
    deleteSlip,
    boatToSlip,
    boatToSea,
} = require('../model/slips');

const controller = {};

// Create a Slip
controller.createSlip = async (req, res) => {
    const params = req.body;
    if (validateSlipParams(params)) {
        const slipId = await createSlip(params, slipsRef);
        const slip = await getSlip(slipId, slipsRef);
        res.status(201).json(slip);
    } else {
        res.status(400).json(error.badRequestError_slip);
    }
};

// Get a Slip
controller.getSlip = async (req, res) => {
    const slipId = req.params.id;
    if (slipId) {
        const slip = await getSlip(slipId, slipsRef);
        if (!slip.id) {
            res.status(404).json(error.notFoundError_slip);
        } else {
            res.status(200).json(slip);
        }
    }
};

// List all Slips
controller.getAllSlips = async (_req, res) => {
    const slips = await getAllSlips(slipsRef);
    res.status(200).json(slips);
};

// Boat Arrives at a Slip
controller.boatToSlip = async (req, res) => {
    const slipId = req.params.slip_id;
    const boatId = req.params.boat_id;

    // Check if the slip and boat exists.
    const slip = await getSlip(slipId, slipsRef);
    const boat = await getBoat(boatId, boatsRef);
    if (!slip.id || !boat.id) {
        res.status(404).json(error.notFoundError_slip_and_or_boat);
    }
    // Check for current boat at slip.
    if (slip.current_boat) {
        res.status(403).json(error.notEmptyError_slip);
    }

    const result = await boatToSlip(slipId, boatId, slipsRef);
    if (result) {
        res.status(204).end();
    }
};

// Boat Departs a Slip
controller.boatToSea = async (req, res) => {
    const slipId = req.params.slip_id;
    const boatId = req.params.boat_id;

    // Check if the boat is at the slip.
    const slip = await getSlip(slipId, slipsRef);
    if (slip.current_boat != boatId) {
        res.status(404).json(error.notFoundError_boat_not_at_slip);
    }

    const result = await boatToSea(slipId, boatId, slipsRef);
    if (result) {
        res.status(204).end();
    }
};

// Delete a Slip
controller.deleteSlip = async (req, res) => {
    const slipId = req.params.id;

    // First check if the slip exists.
    const slipToDelete = await getSlip(slipId, slipsRef);
    if (!slipToDelete.id) {
        res.status(404).json(error.notFoundError_slip);
    } else {
        // Then delete slip.
        const result = await deleteSlip(slipId, slipsRef);
        if (result) {
            res.status(204).end();
        }
    }
};

/**
 * Module exports.
 * @public
 */

 module.exports = controller;