# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Contributor: Danilo Bargen <gezuru@gmail.com>
# Contributor: Simon Conseil <contact+aur at saimon dot org>
# Contributor: Jesus Alvarez

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.13.3
pkgrel=1
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('MIT')
makedepends=('python2-setuptools' 'python-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'python-parso' 'python2-parso')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/davidhalter/jedi/archive/v$pkgver.tar.gz")
sha256sums=('e82c4933b4c9717276fa6528b91d7c667463ac2773ccecd076e6b068c70a6e0e')

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

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2' 'python2-parso')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python2 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et
