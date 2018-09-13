#!/usr/bin/electron

const name = 'code'
const app = require('electron').app;
const path = require('path');

// Remove first command line argument (/usr/bin/electron).
process.argv.splice(0, 1);

// Set application paths.
const appPath = path.join(path.dirname(__dirname), 'lib', name);
app.setName(name);

// Run the application.
require('module')._load(appPath, module, true);

