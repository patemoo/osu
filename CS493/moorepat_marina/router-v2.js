const express = require('express');

const {
    createBoatV2,
    deleteBoatV2,
    viewBoat,
    viewAllBoats,
} = require('./controller/boats');

const {
    assignLoad,
    createLoad,
    deleteLoad,
    viewLoad,
    viewAllLoads,
    viewAllLoadsForBoat
} = require('./controller/loads');

const router = express.Router();

// Create a Boat
router.post('/boats', createBoatV2);

// View a Boat
router.get('/boats/:id', viewBoat);

// View all Boats
router.get('/boats', viewAllBoats);

// Delete a Boat
router.delete('/boats/:id', deleteBoatV2);

// Create a Load
router.post('/loads', createLoad);

// View a Load
router.get('/loads/:id', viewLoad);

// View all Loads
router.get('/loads', viewAllLoads);

// Delete a Load
router.delete('/loads/:id', deleteLoad);

// Managing loads

// Assign Load to Boat
router.put('/boats/:boat_id/loads/:load_id', assignLoad);

// View all loads for a given boat
router.get('/boats/:boat_id/loads', viewAllLoadsForBoat);

/**
 * Module exports.
 * @public
 */

 module.exports = router;