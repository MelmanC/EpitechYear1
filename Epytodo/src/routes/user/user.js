const express = require('express');
const router = express.Router();
const mysql2 = require('mysql2');
const bcrypt = require('bcryptjs');
const jsonweb = require('jsonwebtoken');
const verifyToken = require('../../middleware/auth.js');
require('dotenv').config();
const database = require('../../config/db.js');

router.get('/user', verifyToken, (req, res) => {
    database.query('SELECT * FROM user WHERE id = ?', [req.decoded.id], (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      if (result.length == 0) {
        res.status(401).json({"msg": "Invalid Credentials"});
        return;
      }
      result[0].created_at = new Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
      res.status(200).json(result[0]);
    });
});

router.get('/users/:params', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.params);
  let emailParams = req.params.params;
  if (idParams) {
    database.query('SELECT * FROM user WHERE id = ?', [idParams], (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      if (result.length == 0) {
        res.status(404).json({"msg": "Not found"});
        return;
      }
      result[0].created_at = new Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
      res.status(200).json(result[0]);
    });
  }
  else {
    database.query('SELECT * FROM user WHERE email = ?', [emailParams], (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      if (result.length == 0) {
        res.status(404).json({"msg": "Not found"});
        return;
      }
      result[0].created_at = new Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
      res.status(200).json(result[0]);
    });
  }
});

router.put('/users/:id', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.id);

  const salt = bcrypt.genSaltSync(10);
  req.body.password = bcrypt.hashSync(req.body.password, salt);
  database.query('UPDATE user SET ? WHERE id = ?', [req.body, idParams], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.length == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
  });
  database.query('SELECT * FROM user WHERE id = ?', [idParams], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.length == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
    result[0].created_at = new Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
    res.status(200).json(result[0]);
  });
});

router.delete('/users/:id', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.id);

  database.query('DELETE FROM todo WHERE user_id = ?', [idParams], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.affectedRows == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
  });
  database.query('DELETE FROM user WHERE id = ?', [idParams], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.affectedRows == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
    res.status(200).json({"msg": `Successfully deleted record number : ${idParams}`});
  });
});

router.get('/user/todos', verifyToken, (req, res) => {
  database.query('SELECT * FROM todo WHERE user_id = ?', [req.decoded.id], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.length == 0) {
      res.status(404).json({"msg": "No todos found"});
      return;
    }
    result.forEach((element) => {
      element.created_at = new Date(element.created_at).toISOString().slice(0, 19).replace('T', ' ');
      element.due_time = new Date(element.due_time).toISOString().slice(0, 19).replace('T', ' ');
    });
    res.status(200).json(result);
  });
});

module.exports = router;
