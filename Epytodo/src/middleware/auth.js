const jsonweb = require('jsonwebtoken');

function verifyToken(req, res, next) {
  req.headers.authorization = req.headers.authorization.replace('Bearer ', '');
  if (!req.headers.authorization) {
    res.status(401).json({"msg": "No token, authorization denied"});
    return;
  }
  jsonweb.verify(req.headers.authorization, process.env.SECRET, (err, decoded) => {
    if (err) {
      res.status(401).json({"msg": "Token is not valid"});
      return;
    }
    req.decoded = decoded;
    next();
  });
}

module.exports = verifyToken;
