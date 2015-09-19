"""
Sometimes parts of https://pypi.python.org/pypi/jaraco.util
leak into the python-irc package.  Instead of making a whole
new package for these util functions, let's embed them
instead.  Reconsider this when there is more than a dozen
lines of code.

He also says that "this grab-bag of routines is deprecated"
"""

import six

# from jaraco.util.itertools import always_iterable
def always_iterable(item):
    "taken from jaraco.util-10.0.2"
    if item is None:
        item = ()
    if isinstance(item, six.string_types) or not hasattr(item, '__iter__'):
        item = (item,)
    return item


# from jaraco.util.string import FoldedCase
class FoldedCase(six.text_type):
    """
    A case insensitive string class; behaves just like str
    except compares equal when the only variation is case.
    >>> s = FoldedCase('hello world')

    >>> s == 'Hello World'
    True

    >>> 'Hello World' == s
    True

    >>> s.index('O')
    4

    >>> s.split('O')
    ['hell', ' w', 'rld']

    >>> sorted(map(FoldedCase, ['GAMMA', 'alpha', 'Beta']))
    ['alpha', 'Beta', 'GAMMA']
    """
    def __lt__(self, other):
        return self.lower() < other.lower()

    def __gt__(self, other):
        return self.lower() > other.lower()

    def __eq__(self, other):
        return self.lower() == other.lower()

    def __hash__(self):
        return hash(self.lower())

    # cache lower since it's likely to be called frequently.
    def lower(self):
        self._lower = super(FoldedCase, self).lower()
        self.lower = lambda: self._lower
        return self._lower

    def index(self, sub):
        return self.lower().index(sub.lower())

    def split(self, splitter=' ', maxsplit=0):
        pattern = re.compile(re.escape(splitter), re.I)
        return pattern.split(self, maxsplit)


# from jaraco.util.dictlib import KeyTransformingDict
class KeyTransformingDict(dict):
    """
    A dict subclass that transforms the keys before they're used.
    Subclasses may override the default transform_key to customize behavior.
    """
    @staticmethod
    def transform_key(key):
        return key

    def __init__(self, *args, **kargs):
        super(KeyTransformingDict, self).__init__()
        # build a dictionary using the default constructs
        d = dict(*args, **kargs)
        # build this dictionary using transformed keys.
        for item in d.items():
            self.__setitem__(*item)

    def __setitem__(self, key, val):
        key = self.transform_key(key)
        super(KeyTransformingDict, self).__setitem__(key, val)

    def __getitem__(self, key):
        key = self.transform_key(key)
        return super(KeyTransformingDict, self).__getitem__(key)

    def __contains__(self, key):
        key = self.transform_key(key)
        return super(KeyTransformingDict, self).__contains__(key)

    def __delitem__(self, key):
        key = self.transform_key(key)
        return super(KeyTransformingDict, self).__delitem__(key)

    def setdefault(self, key, *args, **kwargs):
        key = self.transform_key(key)
        return super(KeyTransformingDict, self).setdefault(key, *args, **kwargs)

    def pop(self, key, *args, **kwargs):
        key = self.transform_key(key)
        return super(KeyTransformingDict, self).pop(key, *args, **kwargs)

    def matching_key_for(self, key):
        """
        Given a key, return the actual key stored in self that matches.
        Raise KeyError if the key isn't found.
        """
        try:
            return next(e_key for e_key in self.keys() if e_key == key)
        except StopIteration:
            raise KeyError(key)

