# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Sébastien Luttringer
# Contributor : Ionut Biru <ibiru@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

_name=docutils
pkgname=python-docutils
pkgver=0.20
pkgrel=1
epoch=1
pkgdesc='Set of tools for processing plaintext docs into formats such as HTML, XML, or LaTeX'
arch=('any')
url='http://docutils.sourceforge.net'
license=('custom')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
source=("https://downloads.sourceforge.net/$_name/$_name-$pkgver.tar.gz")
b2sums=('b13f9d4c4dd54b29ff3f93baa8e4a9109c8f719ef62b21b0fceb3f337b5b0b732f3009463c19a1840898217df29e3990e5f24f5c0c17a968386df4c30f021380')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  # we need utf locale to valid utf8 tests
  export LANG=en_US.UTF-8
  PYTHONPATH="$PWD/build/python/" python test/alltests.py
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  # symlink without .py
  for f in "$pkgdir"/usr/bin/*.py; do
      ln -s "$(basename "$f")" "$pkgdir/usr/bin/$(basename "$f" .py)"
  done

  # symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/docutils-$pkgver.dist-info/COPYING.txt \
    "$pkgdir"/usr/share/licenses/$pkgname/COPYING.txt
}

# vim:set ts=2 sw=2 et:
