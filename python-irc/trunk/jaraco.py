"""
Sometimes parts of https://pypi.python.org/pypi/jaraco.util
leak into the python-irc package.  Instead of making a whole
new package for these util functions, let's embed them
instead.  Reconsider this when there is more than a dozen
lines of code.
"""

def always_iterable(item):
    "taken from jaraco.util-10.0.2"
    if item is None:
        item = ()
    if isinstance(item, six.string_types) or not hasattr(item, '__iter__'):
        item = (item,)
    return item

