<?php

define('START_TIME', microtime(true));
include __DIR__ . '/../../examples/debug.php';
define('TESTS_DIR', __DIR__);
$loader = require __DIR__.'/../vendor/autoload.php';
$loader->add('Phal\Mocks', __DIR__);
$loader->add('Phal\Tests', __DIR__);
