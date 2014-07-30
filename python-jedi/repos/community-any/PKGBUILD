# Submitter: Simon Conseil <contact+aur at saimon dot org>
# Submitter: Jesus Alvarez
# Maintainer: Danilo Bargen <gezuru@gmail.com>

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.8.1
_pkgver="${pkgver}-final0"
pkgrel=1
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('MIT')
depends=('python2')
makedepends=('python2-setuptools' 'python-setuptools')
source=("https://pypi.python.org/packages/source/j/jedi/jedi-${_pkgver}.tar.gz")
md5sums=('e4db996421a640d50f559587e805412b')

build() {
   cd "$srcdir/jedi-${_pkgver}"
}

check() {
   cd "$srcdir/jedi-${_pkgver}"
    python3 setup.py test
    python2 setup.py test
}

package_python-jedi() {
    pkgdesc="Awesome autocompletion for python"
    depends=('python')
    conflicts=('python3-jedi-git')
    cd "$srcdir/jedi-${_pkgver}"
    python3 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${_pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-${_pkgver}"
    python2 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${_pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et
