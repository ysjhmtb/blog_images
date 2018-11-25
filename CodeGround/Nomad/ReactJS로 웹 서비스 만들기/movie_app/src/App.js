import React, { Component } from 'react';
import './App.css';
import Movie from './Movie';


class App extends Component {


  // Render : componentWillMount() -> render() -> componentDidMount()
  // Update   componentWillReceiveProps() -> shouldComponentUpdate() -> componentWillUpdate() -> render() -> componentDidUpdate()


  componentWillMount(){
    console.log('will mount');

  }

  componentDidMount(){
    console.log('did mount');

    setTimeout(() => {
      this.setState({
        // movies: [
        //   ...this.state.movies,
        // ]

        movies : [
          {
            title: "Matrix",
            poster: "https://upload.wikimedia.org/wikipedia/en/0/06/Ultimate_Matrix_Collection_poster.jpg"
          },
          {
            title: "Full Metal Jacket",
            poster: "https://www.indiewire.com/wp-content/uploads/2017/07/full-metal-jacket.png?w=780"
          },
          {
            title: "Oldboy",
            poster: "https://upload.wikimedia.org/wikipedia/en/6/67/Oldboykoreanposter.jpg"
          },
          {
            title: "Star Wars",
            poster: "https://imagesvc.timeincapp.com/v3/mm/image?url=https%3A%2F%2Ftimedotcom.files.wordpress.com%2F2017%2F05%2Fstar-wars_1024.jpg&w=700&q=85"
          },
          {
            title: "Terminator",
            poster: "https://cdn-static.denofgeek.com/sites/denofgeek/files/styles/main_wide/public/5/56//arnoldschwarteneggerterminatorgenesys.jpg?itok=59s33g4A"
            
          },
    
        ]
      })
    }, 5000)
    
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
