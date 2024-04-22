#!/usr/bin/node

const request = require('request');

function getCharacterName (url) {
  return new Promise((resolve, reject) => {
    request(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(body.name);
      }
    });
  });
}

function getMovieCharacters (movieId) {
  const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

  request(url, { json: true }, async (error, response, body) => {
    if (error) {
      console.error('Error fetching data:', error);
      return;
    }

    if (body.detail === 'Not found') {
      console.log('Movie not found. Please enter a valid Movie ID.');
      return;
    }

    const characterUrls = body.characters;
    for (const url of characterUrls) {
      try {
        const name = await getCharacterName(url);
        console.log(name);
      } catch (error) {
        console.error('Failed to fetch character:', error);
      }
    }
  });
}

// Check for command-line arguments for Movie ID
if (process.argv.length <= 2) {
  console.log('Please provide a Movie ID as an argument.');
} else {
  const movieId = process.argv[2];
  getMovieCharacters(movieId);
}
