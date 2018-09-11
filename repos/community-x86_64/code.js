#!/usr/bin/electron

const {app} = require('electron');
const path = require('path');

// Remove first command line argument (/usr/bin/electron).
process.argv.splice(0, 1);

// Run the application.
require('module')._load(__dirname, module, true);

