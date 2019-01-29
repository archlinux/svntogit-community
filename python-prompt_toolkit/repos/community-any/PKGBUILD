# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Andy Weidenbaum <archbaum@gmail.com>

pkgbase=python-prompt_toolkit
pkgname=(python-prompt_toolkit python2-prompt_toolkit)
_name=prompt_toolkit
pkgver=2.0.8
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
md5sums=('01f1a16e4e524ec23a9a7a637e8a735a')
sha256sums=('c6655a12e9b08edb8cf5aeab4815fd1e1bdea4ad73d3bbf269cf2e0c4eb75d5e')

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

