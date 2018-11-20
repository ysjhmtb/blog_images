import React, { Component } from 'react';
import './App.css';
import Movie from './Movie';


const movies = [
  {
    id: 1,
    title: "Matrix",
    poster: "https://upload.wikimedia.org/wikipedia/en/0/06/Ultimate_Matrix_Collection_poster.jpg"
  },
  {
    id: 2,
    title: "Full Metal Jacket",
    poster: "https://www.indiewire.com/wp-content/uploads/2017/07/full-metal-jacket.png?w=780"
  },
  {
    id: 3,
    title: "Oldboy",
    poster: "https://upload.wikimedia.org/wikipedia/en/6/67/Oldboykoreanposter.jpg"
  },
  {
    id: 4,
    title: "Star Wars",
    poster: "https://imagesvc.timeincapp.com/v3/mm/image?url=https%3A%2F%2Ftimedotcom.files.wordpress.com%2F2017%2F05%2Fstar-wars_1024.jpg&w=700&q=85"
  }
]

class App extends Component {
  render() {
    return (
      <div className="App">
        {movies.map( (movie, index) => {
          return <Movie title={movie.title} poster={movie.poster} key={index} />
        })}
      </div>
    );
  }
}

export default App;
