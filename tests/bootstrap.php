<?php

define('TESTS_DIR', __DIR__);
$loader = require __DIR__.'/../vendor/autoload.php';
$loader->add('PhpHal\Mocks', __DIR__);
$loader->add('PhpHal\Tests', __DIR__);
