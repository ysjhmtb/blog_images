import React, { Component } from 'react';
import './App.css';
import Movie from './Movie';


class App extends Component {


  // Render : componentWillMount() -> render() -> componentDidMount()
  // Update   componentWillReceiveProps() -> shouldComponentUpdate() -> componentWillUpdate() -> render() -> componentDidUpdate()

  state = {}

  componentWillMount(){
    console.log('will mount');

  }

  componentDidMount(){
    console.log('did mount');

    fetch('https://yts.am/api/v2/list_movies.json?sort_by=download_count')
    
  }


  state = {

    
  }

  _renderMovies = () => {
    const movies = this.state.movies.map( (movie, index) => {
      return <Movie title={movie.title} poster={movie.poster} key={index} />
    })

    return movies;
  }



  render() {

    console.log('did render');


    return (
      <div className="App">
        {this.state.movies ? this._renderMovies() : 'Loading'}
      </div>
    );
  }
}

export default App;
