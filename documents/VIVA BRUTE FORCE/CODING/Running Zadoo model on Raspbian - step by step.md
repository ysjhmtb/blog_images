# Running Zadoo model on Raspbian - step by step

<br>

1) [Easily Format a SD Card in OSX to FAT32](https://www.michaelcrump.net/the-magical-command-to-get-sdcard-formatted-for-fat32/) <br>

```bash
$ diskutil list
$ sudo diskutil eraseDisk FAT32 RASPBIAN MBRFormat /dev/disk2
```

<br>

2) [맥에 라즈비안 OS 설치](https://new93helloworld.tistory.com/238) <br>

```bash
$ diskutil list
$ diskutil unmountDisk /dev/disk2
$ sudo dd bs=1m if=2018-11-13-raspbian-stretch-full.img of=/dev/rdisk2
```

<br>

이 SD 카드를 RPi에 넣어서 부팅.

<br>

3) TF 설치 <br>

[Install TensorFlow with pip ](https://www.tensorflow.org/install/pip)

<br>

[TensorFlow 1.9 Officially Supports the Raspberry Pi](https://medium.com/tensorflow/tensorflow-1-9-officially-supports-the-raspberry-pi-b91669b0aa0)

<br>

```bash
$ python3 --version
$ pip3 --version
$ virtualenv --version

$ sudo apt update
$ sudo apt install python3-dev python3-pip
$ sudo apt install libatlas-base-dev        # required for numpy
$ sudo pip3 install -U virtualenv           # system-wide install


$ virtualenv --system-site-packages -p python3 ./venv
$ source ./venv/bin/activate  # sh, bash, ksh, or zsh
(venv) $ pip install --upgrade pip
(venv) $ pip list  # show packages installed within the virtual environment
(venv) $ deactivate  # don't exit until you're done using TensorFlow


(venv) $ pip install --upgrade tensorflow
(venv) $ python -c "import tensorflow as tf; tf.enable_eager_execution(); print(tf.reduce_sum(tf.random_normal([1000, 1000])))"
```

<br>

4) [mac에 pyenv를 이용해 python 설치하기](https://blog.seotory.com/post/2017/03/install-python-in-mac-using-pyenv)

```bash
$ brew install pyenv
$ pyenv install 3.6.0
$ pyenv global 3.6.0
$ eval "$(pyenv init -)"
$ echo 'eval "$(pyenv init -)"' >> ~/.bash_profile
$ . ~/.bash_profile
```

<br>

5) [맥에서 케라스 설치하기](https://tykimos.github.io/2017/08/07/Keras_Install_on_Mac/)

<br>

```bash
$ sudo pip install virtualenv	# pip3 사용하지 말고 pip라고 한다.
$ virtualenv venv
$ source venv/bin/activate



(venv) $ pip install ipython[notebook]
(venv) $ jupyter notebook



(venv) $ pip install numpy
(venv) $ pip install scipy
(venv) $ pip install scikit-learn
(venv) $ pip install matplotlib
(venv) $ pip install pandas
(venv) $ pip install pydot
(venv) $ pip install h5py 

(venv) $ brew install graphviz

(venv) $ pip install theano
(venv) $ pip install tensorflow
(venv) $ pip install keras

```

<br>

```python
import scipy
import numpy
import matplotlib
import pandas
import sklearn
import pydot
import h5py

import theano
import tensorflow
import keras

print('scipy ' + scipy.__version__)
print('numpy ' + numpy.__version__)
print('matplotlib ' + matplotlib.__version__)
print('pandas ' + pandas.__version__)
print('sklearn ' + sklearn.__version__)
print('pydot ' + pydot.__version__)
print('h5py ' + h5py.__version__)

print('theano ' + theano.__version__)
print('tensorflow ' + tensorflow.__version__)
print('keras ' + keras.__version__)
```

Jupyter 에서 정상적인 출력이 이루어지면 설치가 잘 된 것이다.

<br>

```json
# 백엔드로 구동되는 딥러닝 엔진을 TensorFlow에서 Theano로 변경하려면?
# /Users/yun/.keras/keras.json

{
    "floatx": "float32",
    "epsilon": 1e-07,
    "backend": "theano",
    "image_data_format": "channels_last"
}
```

<br><br>



















[Training and Serving ML models with tf.keras](https://medium.com/tensorflow/training-and-serving-ml-models-with-tf-keras-fd975cc0fa27)











