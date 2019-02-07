# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Andrew Antle <andrew dot antle at gmail dot com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Chaiwat Suttipongsakul <cwt at bashell dot com>

pkgbase=python-markdown
pkgname=('python-markdown' 'python2-markdown')
_pkgbasename=Markdown
pkgver=3.0.1
pkgrel=1
pkgdesc="Python implementation of John Gruber's Markdown."
arch=('any')
url='https://python-markdown.github.io/'
license=('BSD')
depends=('python')
makedepends=('python' 'python2' 'python-setuptools' 'python2-setuptools')
checkdepends=('python-yaml' 'python2-yaml')
source=("https://files.pythonhosted.org/packages/source/M/$_pkgbasename/$_pkgbasename-$pkgver.tar.gz")
md5sums=('72219f46ca440b657bf227500731bdf1')

prepare() {
  # bug in 2.4, some DOS line endings slipped in
  find "$_pkgbasename-$pkgver/" -name '*py' -exec sed -i 's|\r||g' {} +

  cp -r $_pkgbasename-$pkgver "$srcdir/python2-markdown"
  cd "$srcdir/python2-markdown"
  find "$srcdir/python2-markdown" -name '*py' -exec sed -i 's|#!/usr/bin/env python$|&2|' {} +
}

build() {
  cd "$srcdir/$_pkgbasename-$pkgver"
  python setup.py build
  cd "$srcdir/python2-markdown"
  python2 setup.py build
}

check() {
  cd "$srcdir/$_pkgbasename-$pkgver"
  python -m unittest discover tests
  cd "$srcdir/python2-markdown"
  python2 -m unittest discover tests
}

package_python-markdown() {
  depends=('python')
  cd "$srcdir/$_pkgbasename-$pkgver"
  python3 setup.py install --root="$pkgdir" --optimize=0
  install -Dm644 LICENSE.md "$pkgdir/usr/share/licenses/python-markdown/LICENSE"
}

package_python2-markdown() {
  depends=('python2')
  cd "$srcdir/python2-markdown"
  python2 setup.py install --root="$pkgdir" --optimize=0
  mv "$pkgdir/usr/bin/markdown_py" "$pkgdir/usr/bin/markdown_py2"
  install -Dm644 LICENSE.md "$pkgdir/usr/share/licenses/python2-markdown/LICENSE"
}

check_python-markdown() {
  [[ $(python -c "import markdown; print(markdown._get_version())") == "$pkgver" ]]
  [[ $(python -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]
}

check_python2-markdown() {
  [[ $(python2 -c "import markdown; print(markdown._get_version())") == "$pkgver" ]]
  [[ $(python2 -c "import markdown; print(markdown.markdown('*test*'))") == "<p><em>test</em></p>" ]]
}
