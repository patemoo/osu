const { baseUrl, log } = require('../util');

const slips = {};

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

// Returns true if valid, else returns false.
slips.validateSlipParams = (_params) => {
    return _params && _params.number;
}

// Creates a slip; Returns slip id.
slips.createSlip = async (_params, _slipsRef) => {
    try {
        const newSlipRes = await _slipsRef.add(_params);
        return newSlipRes.id;
    } catch(e) {
        log("Create Slip Error: ", e);
    }
};

// Returns a slip if it exists.
slips.getSlip = async (_id, _slipsRef) => {
    try {
        const slipRef = await _slipsRef.doc(String(_id)).get();
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
slips.getAllSlips = async (_slipsRef) => {
    try {
        const allSlips = [];
        const snapshot = await _slipsRef.get();
        snapshot.forEach(slipRef => {
            allSlips.push(slipRefToSlip(slipRef));
        });
        return allSlips;
    } catch(e) {
        log("Get all Slips Error: ", e);
    }
};

// Deletes a slip; Returns write result.
slips.deleteSlip = async (_id, _slipsRef) => {
    try {
        return await _slipsRef.doc(String(_id)).delete();
    } catch(e) {
        log("Delete Slip Error: ", e);
    }
};

// Adds a Boat to a Slip.
slips.boatToSlip = async (_slipId, _boatId, _slipsRef) => {
    try {
        return await _slipsRef.doc(String(_slipId)).update({
            "current_boat": String(_boatId),
        });
    } catch(e) {
        log("Boat Arrives Error: ", e);
    }
};

// Removes a Boat from a Slip.
slips.boatToSea = async (_slipId, _boatId, _slipsRef) => {
    try {
        return await _slipsRef.doc(String(_slipId)).update({
            "current_boat": null,
        });
    } catch(e) {
        log("Boat Departs Error: ", e);
    }
}

/**
 * Module exports.
 * @public
 */

 module.exports = slips;
