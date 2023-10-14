var nodemailer = require('nodemailer');

var transporter = nodemailer.createTransport({
  service: 'gmail',
  auth: {
    user: 'redcraft1234567890@gmail.com',
    pass: 'jc0304(W'
  }
});

var mailOptions = {
    from: 'redcraft1234567890@gmail.com',
    to: 'james@czak.me',
    subject: 'Sending Email using Node.js',
    html: '<h1>Welcome</h1><p>That was easy!</p>'
}

transporter.sendMail(mailOptions, function(error, info){
  if (error) {
    console.log(error);
  } else {
    console.log('Email sent: ' + info.response);
  }
});