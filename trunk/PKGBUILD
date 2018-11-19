# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Andy Weidenbaum <archbaum@gmail.com>

pkgbase=python-prompt_toolkit
pkgname=(python-prompt_toolkit python2-prompt_toolkit python2-prompt_toolkit1)
_name=prompt_toolkit
pkgver=2.0.7
_onever=1.0.15
pkgrel=2
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
source=("https://files.pythonhosted.org/packages/source/p/$_name/$_name-$pkgver.tar.gz"
        "https://files.pythonhosted.org/packages/source/p/$_name/$_name-$_onever.tar.gz")
md5sums=('5c32f640908dec950646a0460198158d'
         '8fe70295006dbc8afedd43e5eba99032')
sha256sums=('fd17048d8335c1e6d5ee403c3569953ba3eb8555d710bfc548faf0712666ea39'
            '858588f1983ca497f1cf4ffde01d978a3ea02b01c8a26a8bbc5cd2e66d816917')

prepare() {
  cd "$srcdir"
  cp -r $_name-$pkgver python2-$_name-$pkgver
  cp -r $_name-$_onever python2-$_name-$_onever
  # rearrange a bunch of stuff to avoid version conflicts
  cd "$srcdir/python2-$_name-$_onever"
  mv -f prompt_toolkit prompt_toolkit1
  find ./ -type f -exec sed -i -e 's/prompt_toolkit/prompt_toolkit1/g' {} \;
}

build() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py build

  cd "$srcdir/python2-$_name-$pkgver"
  python2 setup.py build

  cd "$srcdir/python2-$_name-$_onever"
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

# this is for ipython2
package_python2-prompt_toolkit1() {
  depends=('python2-pygments'
           'python2-six'
           'python2-wcwidth')
  pkgver="$_onever"
  cd "$srcdir/python2-$_name-$_onever"
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

