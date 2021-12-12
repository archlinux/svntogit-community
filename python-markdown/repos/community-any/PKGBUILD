# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Andrew Antle <andrew dot antle at gmail dot com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Chaiwat Suttipongsakul <cwt at bashell dot com>

pkgname=python-markdown
_pkgbasename=Markdown
pkgver=3.3.6
pkgrel=3
pkgdesc="Python implementation of John Gruber's Markdown."
arch=('any')
url='https://python-markdown.github.io/'
license=('BSD')
depends=('python-importlib-metadata')
makedepends=('python-setuptools')
checkdepends=('python-yaml')
source=("https://files.pythonhosted.org/packages/source/M/$_pkgbasename/$_pkgbasename-$pkgver.tar.gz")
sha256sums=('76df8ae32294ec39dcf89340382882dfa12975f87f45c3ed1ecdb1e8cefc7006')

build() {
  cd "$_pkgbasename-$pkgver"
  python setup.py build
}

check() {
  cd "$_pkgbasename-$pkgver"
  [[ $(python -c "import markdown; print(markdown.version)") == "$pkgver" ]]
  [[ $(python -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]
  python -m unittest discover tests
}

package() {
  cd "$_pkgbasename-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.md "$pkgdir/usr/share/licenses/python-markdown/LICENSE"
}
