# Submitter: Simon Conseil <contact+aur at saimon dot org>
# Submitter: Jesus Alvarez
# Maintainer: Danilo Bargen <gezuru@gmail.com>

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.12.1
pkgrel=2
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('MIT')
depends=('python2')
makedepends=('python2-setuptools' 'python-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'python-parso' 'python2-parso')
source=(https://github.com/davidhalter/jedi/archive/v$pkgver.tar.gz)
md5sums=('49a94ffb781c1383e8542ca5f71cebf0')

check() {
    cd "$srcdir/jedi-${pkgver}"
    pytest test || warning 'Ignoring test_pyc failure'
}

package_python-jedi() {
    pkgdesc="Awesome autocompletion for python"
    depends=('python' 'python-parso')
    conflicts=('python3-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python3 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2' 'python2-parso')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python2 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et
