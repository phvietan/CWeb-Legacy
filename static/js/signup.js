function validateUsername(documentUsername) {
  const username = documentUsername.value;
  if (username.length > 40) {
    alert("Username is too long, exceed 40 characters");
    return false;
  }

  const nameRegex = /^[a-zA-Z0-9]+$/;
  const isValid = nameRegex.test(username);
  if (!isValid) {
    alert("Invalid username. Only characters A-Z, a-z and 0-9 are  acceptable.");
    documentUsername.focus();
  }
  return isValid;
}

function validateEmail(documentEmail) {
  const email = documentEmail.value;
  if (email.length > 40) {
    alert("Email is too long, exceed 40 characters");
    return false;
  }

  const emailRegex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  const isValid = emailRegex.test(email);
  if (!isValid) {
    alert("Invalid email.");
    documentEmail.focus();
  }
  return isValid;
}

function validatePassword(documentPassword) {
  const password = documentPassword.value;
  if (password.length > 40) {
    alert("Password is too long, exceed 40 characters");
    return false;
  }

  const passwordRegex = /^[a-zA-Z0-9]+$/;
  const isValid = passwordRegex.test(password);
  if (!isValid) {
    alert("Invalid password. Only characters A-Z, a-z and 0-9 are allowed.");
    documentPassword.focus();
  }
  return isValid;
}

async function postRequest(req) {
  const xhr = new XMLHttpRequest();
  xhr.open("POST", '/api/user/signup', true);
  xhr.setRequestHeader("Content-Type", "application/json");
  xhr.onreadystatechange = function() { // Call a function when the state changes.
    if (this.readyState === XMLHttpRequest.DONE && this.status === 200) {
      console.log(xhr.responseText);
    }
  }
  xhr.send(JSON.stringify(req));
}

async function signup() {
  const documentUsername = document.getElementById('signup-username');
  const isValidUsername = validateUsername(documentUsername);
  if (!isValidUsername) return;

  const documentEmail = document.getElementById('signup-email');
  const isValidEmail = validateEmail(documentEmail);
  if (!isValidEmail) return;

  const documentPassword = document.getElementById('signup-password');
  const isValidPassword = validatePassword(documentPassword);
  if (!isValidPassword) return;

  const username = documentUsername.value;
  const email = documentEmail.value;
  const password = documentPassword.value;
  await postRequest({ username, email, password });
}