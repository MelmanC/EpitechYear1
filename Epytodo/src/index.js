const express = require('express');
const auth = require('./routes/auth/auth');
const user = require('./routes/user/user.js');
const todos = require('./routes/todos/todos.js');
const middleauth = require('./middleware/auth.js');
require('dotenv').config();
const app = express();

const port = process.env.PORT || 3000;

app.use('/', auth);

app.use('/', user);

app.use('/', todos);

app.listen(port, process.env.MYSQL_HOST, () => {
  console.log(`Server is running on ${process.env.MYSQL_HOST}:${port}`);
});
