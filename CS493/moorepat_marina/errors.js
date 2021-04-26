'use strict';

const error = {
    alreadyAssigned_load: {
        Error: "The load with load_id is already assigned"
    },
    badRequestError_boat: {
        Error: "The request object is missing at least one of the required attributes"
    },
    badRequestError_slip: {
        Error: "The request object is missing the required number"
    },
    badRequestError_load: {
        Error: "The request object is missing at least one of the required attributes"
    },
    notFoundError_boat: {
        Error: `No boat with this boat_id exists`
    },
    notFoundError_slip: {
        Error: "No slip with this slip_id exists"
    },
    notFoundError_load: {
        Error: "No load with this load_id exists"
    },
    notFoundError_slip_and_or_boat: {
        Error: "The specified boat and/or slip does not exist"
    },
    notFoundError_boat_not_at_slip: {
        Error: "No boat with this boat_id is at the slip with this slip_id"
    },
    notEmptyError_slip: {
        Error: "The slip is not empty"
    },
};

/**
 * Module exports.
 * @public
 */

module.exports = error;