# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Andrew Antle <andrew dot antle at gmail dot com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Chaiwat Suttipongsakul <cwt at bashell dot com>

pkgname=python-markdown
pkgver=3.4.1
pkgrel=2
pkgdesc="Python implementation of John Gruber's Markdown"
arch=('any')
url='https://python-markdown.github.io/'
license=('BSD')
depends=('python')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-yaml')
_commit='f588d8b0f2877c6aa5ac352d27c6f37bdbd41869'
source=("$pkgname::git+https://github.com/Python-Markdown/markdown#commit=$_commit")
sha256sums=('SKIP')

pkgver() {
  cd "$pkgname"

  git describe --tags | sed 's/^v//'
}

build() {
  cd "$pkgname"

  python -m build --wheel --no-isolation
}

check() {
  cd "$pkgname"

  [[ $(python -c "import markdown; print(markdown.__version__)") == "$pkgver" ]]
  [[ $(python -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]

  python -m unittest discover tests
}

package() {
  cd "$pkgname"

  python -m installer --destdir="$pkgdir" dist/*.whl

  # license
  install -vDm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE.md
}
