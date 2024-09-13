const express = require('express');
const router = express.Router();
const mysql2 = require('mysql2');
const bcrypt = require('bcryptjs');
const jsonweb = require('jsonwebtoken');
require('dotenv').config();
router.use(express.json());
const database = require('../../config/db.js');

router.post('/register', (req, res) => {
    const email = req.body.email;
    const name = req.body.name;
    const firstname = req.body.firstname;
    const password = req.body.password;

    if (!name || !email || !password || !firstname) {
        res.status(400).json({"msg": "Bad parameter"});
        return;
    }
    database.query('SELECT * FROM user WHERE email = ?', [email], (err, result) => {
        if (err) {
            res.status(500).json({"msg": "Internal server error"});
            return;
        }
        if (result.length > 0) {
            res.status(409).json({"msg": "Account already exists"});
            return;
        }
        const salt = bcrypt.genSaltSync(10);
        const hash = bcrypt.hashSync(password, salt);
        database.query('INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)', [email, name, firstname, hash], (err, result) => {
            if (err) {
              res.status(500).json({"msg": "Internal server error"});
              return;
            }
            res.status(201).json({"token": "Token of the newly registered user"});
        });
    });
});

router.post('/login', (req, res) => {
    const email = req.body.email;
    const password = req.body.password;

    if (!email || !password) {
        res.status(400).json({"msg": "Bad parameter"});
        return;
    }
    database.query('SELECT * FROM user WHERE email = ? ' , [email], (err, result) => {
        if (err) {
            res.status(500).json({"msg": "Internal server error"});
            return;
        }
        if (result.length == 0) {
            res.status(401).json({"msg": "Invalid Credentials"});
            return;
        }
        if (bcrypt.compareSync(password, result[0].password) == false) {
            res.status(401).json({"msg": "Invalid Credentials"});
            return;
        }
        const payload = {
            id: result[0].id,
            email: result[0].email
        };
        const token = jsonweb.sign(payload, process.env.SECRET);
        res.status(200).json({"token": token});
    });
});

module.exports = router;
