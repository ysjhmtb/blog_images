import React, { Component } from 'react';
import PhoneForm from './components/PhoneForm';

class App extends Component {

  id = 0;

  state = {
    information: [],
  }

  handleCreate = (data) => {

    // 자식 클래스에서 state를 전달받는다.
    console.log(data);

    const {information} = this.state;
    this.setState({
      information: information.concat({
        ...data,
        id: this.id++,
      })
    }); 
  }

  render() {
    return (
      <div>
        <PhoneForm onCreate={this.handleCreate} />
      </div>
    );
  }
}

export default App;
