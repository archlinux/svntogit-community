# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Andy Weidenbaum <archbaum@gmail.com>

pkgbase=python-prompt_toolkit
pkgname=(python-prompt_toolkit python2-prompt_toolkit)
_name=prompt_toolkit
pkgver=2.0.9
pkgrel=1
pkgdesc="Library for building powerful interactive command lines in Python"
arch=('any')
depends=('python-pygments'
         'python-six'
         'python-wcwidth')
makedepends=('python-setuptools' 'python2-setuptools'
             'python2-pygments' 'python2-six' 'python2-wcwidth')
url="https://github.com/jonathanslenders/python-prompt-toolkit"
license=('BSD')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/p/$_name/$_name-$pkgver.tar.gz")
md5sums=('091daddeec62015e0be36e8682d36562')
sha256sums=('2519ad1d8038fd5fc8e770362237ad0364d16a7650fb5724af6997ed5515e3c1')

prepare() {
  cd "$srcdir"
  cp -r $_name-$pkgver python2-$_name-$pkgver
}

build() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py build

  cd "$srcdir/python2-$_name-$pkgver"
  python2 setup.py build
}

package_python-prompt_toolkit() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-prompt_toolkit() {
  depends=('python2-pygments'
           'python2-six'
           'python2-wcwidth')
  cd "$srcdir/python2-$_name-$pkgver"
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

