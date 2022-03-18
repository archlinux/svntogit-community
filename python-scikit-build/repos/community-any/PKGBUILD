# Maintainer: Andrzej Giniewicz <gginiu@gmail.com>
# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Martino Pilia <martino.pilia@gmail.com>
# Contributor: Ben Greiner <code-arch@bnavigator.de>

pkgname=python-scikit-build
pkgver=0.13.1
pkgrel=2
pkgdesc="Improved build system generator for CPython C, C++, Cython and Fortran extensions"
arch=(any)
url="https://scikit-build.org"
license=(MIT)
depends=(cmake python-distro python-packaging python-setuptools python-wheel)
makedepends=(git python-setuptools-scm)
checkdepends=(
    cython
    gcc
    gcc-fortran
    ninja
    python-build
    python-path
    python-pytest
    python-pytest-mock
    python-pytest-runner
    python-pytest-virtualenv
    python-requests
    python-six
    python-virtualenv
)
_tag=9295c828189c3d7a813b2faf04f535f777d33254 # git rev-parse ${pkgver}
source=(git+https://github.com/scikit-build/scikit-build.git#tag=${_tag}?signed
        ${pkgname}-use-setuptools-scm.patch::https://github.com/scikit-build/scikit-build/commit/22b96b747c5276d0e6c3673f350267d6177e9310.patch
        fix-byte-compilation.patch)
sha256sums=('SKIP'
            '928670f003cf94ee1612702a03bd341338bd1a7a63222d30ca3efb8601d70bca'
            '4300d021991de1537ee746e3a7006a0b286a86295f0f7cf41d4aab72e4e14f89')
validpgpkeys=(2FDEC9863E5E14C7BC429F27B9D0E45146A241E8) # Henry Schreiner <hschrein@cern.ch>

prepare() {
  cd scikit-build
  # Fix SCM detected version
  patch -p1 < ../${pkgname}-use-setuptools-scm.patch
  rm -r .git
  echo "Version: ${pkgver}" > PKG-INFO
  # Backport of https://github.com/scikit-build/scikit-build/pull/678
  patch -p1 < ../fix-byte-compilation.patch
}

build() {
  cd scikit-build
  python setup.py build_ext --inplace
  python setup.py build
}

check() {
  cd scikit-build
  # Disable coverage
  sed -i 's|--cov --cov-report xml ||' setup.cfg
  python -m venv --system-site-packages test-env
  test-env/bin/python /usr/bin/pytest -x -vv --color=yes
}

package() {
  cd scikit-build
  python setup.py install --skip-build --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
