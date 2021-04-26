const Firestore = require('@google-cloud/firestore');
const { log } = require('./util');

const db = new Firestore({
    projectId: 'corded-imagery-309502',
    keyFilename: process.env.GOOGLE_APPLICATION_CREDENTIALS,
});

const boatsRef = db.collection('boats');
const slipsRef = db.collection('slips');
const loadsRef = db.collection('loads');

exports = module.exports;

exports.boatsRef = boatsRef;
exports.slipsRef = slipsRef;
exports.loadsRef = loadsRef;

exports.getBoatRef = (_id) => {
    try {
        return boatsRef.doc(String(_id));
    } catch(e) {
        log("Error: ", e);
    }
}

exports.getBoat = async (_id) => {
    try {
        return await boatsRef.doc(String(_id)).get();
    } catch(e) {
        log("Error: ", e);
    }
}

exports.getBoatData = async (_id) => {
    try {
        const doc = await boatsRef.doc(String(_id)).get();
        return doc.data();
    } catch(e) {
        log("Error: ", e);
    }
}

exports.getLoad = async (_id) => {
    try {
        return await loadsRef.doc(String(_id)).get();
    } catch(e) {
        log("Error: ", e);
    }
}

exports.getLoadData = async (_id) => {
    try {
        const doc = await loadsRef.doc(String(_id)).get();
        return doc.data();
    } catch(e) {
        log("Error: ", e);
    }
}