# Submitter: Simon Conseil <contact+aur at saimon dot org>
# Submitter: Jesus Alvarez
# Maintainer: Danilo Bargen <gezuru@gmail.com>

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
pkgver=0.10.2
pkgrel=1
arch=('any')
url="https://github.com/davidhalter/jedi"
license=('MIT')
depends=('python2')
makedepends=('python2-setuptools' 'python-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=('https://pypi.python.org/packages/80/b9/4e9b0b999deeec8a91cb84e567380853a842e6c387c9d39b8fc9a49953fa/jedi-0.10.2.tar.gz')
md5sums=('b2b35b4b7e508ec3a54d94cdea1205d0')

check() {
   cd "$srcdir/jedi-${pkgver}"
   pytest test

}

package_python-jedi() {
    pkgdesc="Awesome autocompletion for python"
    depends=('python')
    conflicts=('python3-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python3 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

package_python2-jedi() {
    pkgdesc="Awesome autocompletion for python2"
    depends=('python2')
    conflicts=('jedi-git' 'python2-jedi-git')
    cd "$srcdir/jedi-${pkgver}"
    python2 setup.py install --root="$pkgdir/" --optimize=1

    install -D -m644 "$srcdir/jedi-${pkgver}/LICENSE.txt" $pkgdir/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et
