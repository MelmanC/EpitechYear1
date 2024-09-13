const express = require('express');
const router = express.Router();
const mysql2 = require('mysql2');
const bcrypt = require('bcryptjs');
const jsonweb = require('jsonwebtoken');
const verifyToken = require('../../middleware/auth.js');
require('dotenv').config();
const database = require('../../config/db.js');

router.get('/todos', verifyToken, (req, res) => {
    database.query('SELECT * FROM todo', (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      if (result.length == 0) {
        res.status(404).json({"msg": "Not found"});
        return;
      }
      result.forEach((element) => {
        element.created_at = new Date(element.created_at).toISOString().slice(0, 19).replace('T', ' ');
        element.due_time = new Date(element.due_time).toISOString().slice(0,
          19).replace('T', ' ');
      });
      res.status(200).json(result);
    });
});

router.get('/todos/:id', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.id);

  database.query('SELECT * FROM todo WHERE id = ? AND user_id = ?', [idParams,
    req.decoded.id], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
     return;
    }
    if (result.length == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
    result[0].created_at = new
      Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
    result[0].due_time = new Date(result[0].due_time).toISOString().slice(0,
      19).replace('T', ' ');
    res.status(200).json(result[0]);
  });
});

router.post('/todos', verifyToken, (req, res) => {
  let title = req.body.title;
  let description = req.body.description;
  let due_time = req.body.due_time;
  let user_id = req.body.user_id;
  let status = req.body.status;

  if (!title || !description || !due_time || !user_id || !status) {
    res.status(400).json({"msg": "Bad parameter"});
    return;
  }
  if (req.decoded.id != user_id) {
      res.status(401).json({"msg": "Invalid Credentials"});
      return;
  }
  database.query('INSERT INTO todo (title, description, due_time, user_id, status) VALUES (?, ?, ?, ?, ?)', [title, description, due_time, user_id, status], (err, result) => {
    if (err) {
      res.status(500).json({"msg": "Internal server error"});
      return;
    }
    if (result.affectedRows == 0) {
      res.status(404).json({"msg": "Not found"});
      return;
    }
    database.query('SELECT * FROM todo WHERE id = ?', [result.insertId], (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      result[0].created_at = new Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
      result[0].due_time = new Date(result[0].due_time).toISOString().slice(0, 19).replace('T', ' ');
      res.status(201).json(result[0]);
    });
  });
});

router.put('/todos/:id', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.id);
  let { title, description, due_time, user_id, status } = req.body;

  if (!title || !description || !due_time || !user_id || !status) {
    res.status(400).json({"msg": "Bad parameter"});
    return;
  }
  if (req.decoded.id != user_id) {
      res.status(404).json({"msg": "Invalid Credentials"});
      return;
    }
    database.query('UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?', [title, description, due_time, user_id, status, idParams], (err, result) => {
      if (err) {
        res.status(500).json(err);
        return;
      }
      if (result.affectedRows == 0) {
        res.status(404).json({"msg": "Not found"});
        return;
      }
      database.query('SELECT * FROM todo WHERE id = ?', [idParams], (err,
        result) => {
        if (err) {
          res.status(500).json(err);
          return;
        }
        result[0].created_at = new
          Date(result[0].created_at).toISOString().slice(0, 19).replace('T', ' ');
        result[0].due_time = new
          Date(result[0].due_time).toISOString().slice(0, 19).replace('T', ' ');
        res.status(200).json(result[0]);
      });
    });
});

router.delete('/todos/:id', verifyToken, (req, res) => {
  let idParams = parseInt(req.params.id);

  database.query('DELETE FROM todo WHERE id = ? AND user_id = ?', [idParams, req.decoded.id], (err, result) => {
      if (err) {
        res.status(500).json({"msg": "Internal server error"});
        return;
      }
      if (result.affectedRows == 0) {
        res.status(404).json({"msg": "Invalid Credentials"});
        return;
      }
      res.status(200).json({"msg" : `Successfully deleted record number: ${idParams}`});
    });
});

module.exports = router;
