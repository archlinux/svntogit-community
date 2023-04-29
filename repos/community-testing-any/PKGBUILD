# Maintainer: Kyle Keen < keenerd at gmail >
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Mike Sampson <mike at sambodata dot com>
# Contributor: Anton Bazhenov <anton.bazhenov at gmail>

pkgname=bpython
pkgver=0.24
pkgrel=3
pkgdesc='Fancy ncurses interface to the Python interpreter'
arch=('any')
url='https://bpython-interpreter.org/'
license=('MIT')
depends=('python-pygments' 'python-requests' 'python-curtsies' 'python-greenlet'
         'python-typing_extensions' 'python-pyxdg')
optdepends=('python-urwid: for bpython-urwid'
            'python-jedi: multiline completion'
            'python-watchdog: module reloading')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest')
#source=(https://bpython-interpreter.org/releases/bpython-${pkgver}.tar.gz)  # slow
#source=("https://github.com/bpython/bpython/archive/$pkgver-release.tar.gz")  # missing version data
source=("https://files.pythonhosted.org/packages/source/b/bpython/bpython-$pkgver.tar.gz")
sha256sums=('98736ffd7a8c48fd2bfb53d898a475f4241bde0b672125706af04d9d08fd3dbd')

build() {
  cd bpython-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd bpython-$pkgver
  pytest --deselect bpython/test/test_interpreter.py::TestInterpreter::test_syntaxerror
}

package() {
  cd bpython-$pkgver

  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/bpython/LICENSE"
}
