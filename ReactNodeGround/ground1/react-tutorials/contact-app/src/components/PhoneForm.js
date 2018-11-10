import React, { Component } from 'react';

class PhoneForm extends Component {

    state = {
        name: '',
        phone: '',
    }

    handleChange = (e) => {
        this.setState({
            [e.target.name]: e.target.value
        });
    }

    
    handleSubmit = (e) => {
        // form 속성이 submit 버튼을 누르면 새로고침을 하게 된다. 이를 방지할 필요가 있다.
        e.preventDefault();
        // 부모 클래스에게 state가 전달된다.
        this.props.onCreate(this.state);  
        // 등록하고 나면 초기화
        this.setState({
            name: '',
            phone: '',
        }) 
        
    }

    render() {
        return (
            <form onSubmit={this.handleSubmit}> 
                <input 
                    name="name"
                    placeholder="이름" 
                    onChange={this.handleChange} 
                    value={this.state.name} />

                <input 
                    name="phone"
                    placeholder="전화번호" 
                    onChange={this.handleChange}
                    value={this.state.phone} />

                <button type="submit">등록</button>

                 
            </form>
        );
    }
}

export default PhoneForm;