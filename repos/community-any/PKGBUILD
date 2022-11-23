# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Liam Timms <timms5000@gmail.com>
# Contributor: Michel Zou

pkgname=python-nbsphinx
pkgver=0.8.10
pkgrel=1
pkgdesc="Jupyter Notebook Tools for Sphinx"
url="http://nbsphinx.rtfd.org/"
arch=(any)
license=('MIT')
depends=('python-docutils' 'python-jinja' 'jupyter-nbconvert' 'jupyter-nbformat' 'python-sphinx')
makedepends=('python-build' 'python-installer' 'python-wheel' 'python-setuptools-scm')
source=("$pkgname-$pkgver.tar.gz::https://github.com/spatialaudio/nbsphinx/archive/${pkgver}.tar.gz")
sha256sums=('568de199d1c42e74679f3a42feead828b43de48273079b6e05a228cc3a48b2f0')

build() {
  cd "${srcdir}"/nbsphinx-$pkgver
  python -m build --wheel --no-isolation
}

package() {
  cd "${srcdir}/nbsphinx-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
