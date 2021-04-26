const express = require('express');

const {
    createBoat,
    getBoat,
    getAllBoats,
    updateBoat,
    deleteBoat,
} = require('./controller/boats');

const {
    createSlip,
    getSlip,
    getAllSlips,
    deleteSlip,
    boatToSlip,
    boatToSea,
} = require('./controller/slips');

const router = express.Router();

router.get('/env', (req, res) => {
    res.status(200).json({"NODE_ENV": process.env.NODE_ENV});
});

// Create a Boat
router.post('/boats', createBoat);

// Get a Boat
router.get('/boats/:id', getBoat);

// List all Boats
router.get('/boats', getAllBoats);

// Edit a Boat
router.patch('/boats/:id', updateBoat);

// Delete a Boat
router.delete('/boats/:id', deleteBoat);


// Create a Slip
router.post('/slips', createSlip);

// Get a Slip
router.get('/slips/:id', getSlip);

// List all Slips
router.get('/slips', getAllSlips);

// Boat Arrives at a Slip
router.put('/slips/:slip_id/:boat_id', boatToSlip);

// Boat Departs a Slip
router.delete('/slips/:slip_id/:boat_id', boatToSea);

// Delete a Slip
router.delete('/slips/:id', deleteSlip);

/**
 * Module exports.
 * @public
 */

 module.exports = router;