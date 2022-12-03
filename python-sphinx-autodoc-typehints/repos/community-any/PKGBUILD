# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-autodoc-typehints
_pyname=${pkgname/python-/}
_gitcommit=9d67010bcc5cd7d1d917069b75e43057551af7be
pkgver=1.19.5
pkgrel=1
pkgdesc='Type hints support for the Sphinx autodoc extension'
url='https://github.com/agronholm/sphinx-autodoc-typehints'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx' 'python-typing_extensions')
makedepends=('git' 'python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs')
checkdepends=('python-pytest' 'python-sphobjinv' 'python-nptyping')
source=("git+https://github.com/agronholm/sphinx-autodoc-typehints#commit=${_gitcommit}")
sha512sums=('SKIP')

pkgver() {
  cd ${_pyname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

build() {
  cd ${_pyname}
  python -m build --wheel --no-isolation
}

check() {
  cd ${_pyname}
  PYTHONPATH="$PWD/src" pytest
}

package() {
  cd ${_pyname}
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
