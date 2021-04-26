const { baseUrl, log } = require('../util');

// Load interface:
/* 
    id: number: // auto generated.
    volume: number;
    carrier: Boat | null;
    content: string;
    creation_date: Date;
    self: string; // api endpoint. not in db.
*/

const loads = {};

const getDateString = () => {
    const today = new Date();
    const date = today.getUTCDate();
    const month = today.getUTCMonth();
    const year = today.getUTCFullYear();
    const dateString = `${month}/${date}/${year}`;

    return dateString;
}

// Returns a loat including id and self (endpoint).
const loadRefToLoad = (_load) => {
    const loadId = _load.id;
    const loadData = _load.data();
    const load = {
        id: loadId,
        ...loadData,
        self: `${baseUrl}/v2/loads/${loadId}`,
    }
    const carrier = loadData.carrier;
    if (carrier) {
        load.carrier = {
            id: carrier.id,
            name: carrier.name,
            self: `${baseUrl}/v2/boats/${carrier.id}`,
        }
    }
    return load;
};

// Returns true if valid, else returns false.
loads.validateLoadParams = (_params) => {
    return _params && _params.content && _params.volume;
};

// Creates a load: Returns load id.
loads.createLoad = async (_params, _collection) => {
    _params.creation_date = getDateString();
    _params.carrier = null;
    try {
        const newLoadRes = await _collection.add(_params);
        return newLoadRes.id;
    } catch (e) {
        log("Create Load Error: ", e);
    }
};

// Returns a load if it exists.
loads.viewLoad = async (_id, _collection) => {
    try {
        const loadRef = await _collection.doc(String(_id)).get();
        if (!loadRef.exists) {
            log(`A load with an id of ${_id} does not exist.`);
            return {};
        } else {
            return loadRefToLoad(loadRef);
        }
    } catch(e) {
        log("View Load Error: ", e);
    }
};

// Returns all loads.
loads.viewAllLoads = async (_collection) => {
    try {

    } catch(e) {
        log("View all Loads Error: ", e);
    }
};

// Assign a load to a boat.
loads.assignLoad = async (_boatId, _loadId, _boatsRef, _loadsRef) => {
    var boatRef;
    var loadRef;
    try {
        boatRef = await _boatsRef.doc(String(_boatId));
        loadRef = await _loadsRef.doc(String(_loadId));
    } catch(e) {
        log("Get Error: ", e);
    }
    const boat = await boatRef.get();
    const boatData = boat.data();
    const loads = boatData.loads ? boatData.loads : [];
    loads.push(loadRef.id);
    try {
        await boatRef.update({loads: loads});
        await loadRef.update({carrier: {
            id: boatRef.id,
            name: boatData.name,
        }});
    } catch(e) {
        log("Assign a Load Error: ", e);
    }
}

// Remove a load from a boat.
loads.removeLoad = async (_boatRef, _loadRef) => {
    const boatData = _boatRef.data();
    const loads = loads.filter(loadId => loadId != _loadRef.id);
    try {
        await _boatRef.update({loads: loads});
        await _loadRef.update({carrier: null});
    } catch(e) {
        log("Remove a Load Error: ", e);
    }
}

// Deletes a load; Returns write result.
loads.deleteLoad = async (_id, _collection) => {
    try {
        // remove load from boat.
        // then delete load.
    } catch(e) {
        log("Delete Load Error: ", e);
    }
};

/**
 * Module exports.
 * @public
 */

 module.exports = loads;