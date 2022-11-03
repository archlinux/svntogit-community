#!/usr/bin/env python

import tensorflow as tf

with tf.device("/GPU:0"):
    a = tf.random.normal([1, 2])


def temp(x):
    return tf.shape(x)[0]

tf.autograph.to_graph(temp)
