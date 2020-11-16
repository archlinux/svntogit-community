# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Andrew Antle <andrew dot antle at gmail dot com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Chaiwat Suttipongsakul <cwt at bashell dot com>

pkgname=python-markdown
_pkgbasename=Markdown
pkgver=3.3.3
pkgrel=2
pkgdesc="Python implementation of John Gruber's Markdown."
arch=('any')
url='https://python-markdown.github.io/'
license=('BSD')
depends=('python' 'python-setuptools')
checkdepends=('python-yaml')
source=("https://files.pythonhosted.org/packages/source/M/$_pkgbasename/$_pkgbasename-$pkgver.tar.gz")
sha256sums=('5d9f2b5ca24bc4c7a390d22323ca4bad200368612b5aaa7796babf971d2b2f18')

build() {
  cd "$srcdir/$_pkgbasename-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/$_pkgbasename-$pkgver"
  python -m unittest discover tests
}

package() {
  cd "$srcdir/$_pkgbasename-$pkgver"
  python3 setup.py install --root="$pkgdir" --optimize=0
  install -Dm644 LICENSE.md "$pkgdir/usr/share/licenses/python-markdown/LICENSE"
}

check_python-markdown() {
  [[ $(python -c "import markdown; print(markdown.version)") == "$pkgver" ]]
  [[ $(python -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]
}
