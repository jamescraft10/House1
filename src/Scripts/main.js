const imageForm = document.getElementById('image-form');
const imageInput = document.getElementById('image-input');
const imageContainer = document.getElementById('image-container');

imageForm.addEventListener('submit', (e) => {
  e.preventDefault();

  const formData = new FormData();
  formData.append('image', imageInput.files[0]);

  fetch('/upload', {
    method: 'POST',
    body: formData
  })
  .then(response => response.json())
  .then(data => {
    const imageUrl = data.imageUrl;
    const imgElement = document.createElement('img');
    imgElement.src = imageUrl;
    imageContainer.appendChild(imgElement);
  })
  .catch(error => {
    console.error('Error:', error);
  });
});

const socket = io();

socket.on('image', (imageUrl) => {
  const imgElement = document.createElement('img');
  imgElement.src = imageUrl;
  imageContainer.appendChild(imgElement);
});

socket.on('chat message', (msg) => {
  // Handle chat messages as you did before
});