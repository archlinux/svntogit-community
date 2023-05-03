# Maintainer: Andrzej Giniewicz <gginiu@gmail.com>
# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Martino Pilia <martino.pilia@gmail.com>
# Contributor: Ben Greiner <code-arch@bnavigator.de>

pkgname=python-scikit-build
pkgver=0.17.1
pkgrel=2
pkgdesc="Improved build system generator for CPython C, C++, Cython and Fortran extensions"
arch=(any)
url="https://scikit-build.org"
license=(MIT)
depends=(cmake python-distro python-packaging python-setuptools python-wheel)
makedepends=(git python-build python-installer python-hatchling python-hatch-vcs python-hatch-fancy-pypi-readme)
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
_tag=6e47f59cb4c0057e5559e02c4d30a0619f636d30 # git rev-parse ${pkgver}
source=(git+https://github.com/scikit-build/scikit-build.git#tag=${_tag}?signed)
sha256sums=('SKIP')
validpgpkeys=(2FDEC9863E5E14C7BC429F27B9D0E45146A241E8) # Henry Schreiner <hschrein@cern.ch>

build() {
  cd scikit-build
  python -m build --wheel --no-isolation
}

check() {
  cd scikit-build
  # Disable coverage
  sed -i 's|\"--cov\"\, \"--cov-report=xml\"||' noxfile.py
  # Tests need a rw version of site-packages
  python -m venv --system-site-packages test-env
  # https://github.com/scikit-build/scikit-build/issues/727
  test-env/bin/python /usr/bin/pytest -vv --color=yes || echo "Tests failed"
}

package() {
  cd scikit-build
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
