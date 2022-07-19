# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Andrew Antle <andrew dot antle at gmail dot com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Chaiwat Suttipongsakul <cwt at bashell dot com>

pkgname=python-markdown
_pkgbasename=Markdown
pkgver=3.4.1
pkgrel=1
pkgdesc="Python implementation of John Gruber's Markdown."
arch=('any')
url='https://python-markdown.github.io/'
license=('BSD')
depends=('python-importlib-metadata')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-yaml')
source=("https://files.pythonhosted.org/packages/source/M/$_pkgbasename/$_pkgbasename-$pkgver.tar.gz")
sha256sums=('3b809086bb6efad416156e00a0da66fe47618a5d6918dd688f53f40c8e4cfeff')

build() {
  cd "$_pkgbasename-$pkgver"
  python -m build -wn
}

check() {
  cd "$_pkgbasename-$pkgver"
  [[ $(python -c "import markdown; print(markdown.__version__)") == "$pkgver" ]]
  [[ $(python -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]
  python -m unittest discover tests
}

package() {
  cd "$_pkgbasename-$pkgver"
  python -m installer --d "$pkgdir" dist/*.whl
  install -Dm0644 -t "$pkgdir/usr/share/licenses/python-markdown/" LICENSE.md
}
