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

4) How to call a trained TensorFlow model in C++ 

<br>

 