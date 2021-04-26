exports = module.exports;

const isDevEnv = process.env.NODE_ENV == "development";
exports.isDevEnv = isDevEnv;

exports.baseUrl = isDevEnv ? "http://localhost:8080" : "https://corded-imagery-309502.uk.r.appspot.com";

// Log:
exports.log = (...args) => {
    if (isDevEnv) {
        console.log(...args);
    }
} 