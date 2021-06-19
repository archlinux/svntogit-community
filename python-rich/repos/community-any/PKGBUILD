# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=10.4.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-pip' 'python-poetry')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('76874e3efd9a8d696ba96579e1c658b1c76e71d353574cf3f9fb5d8a15810879f649d0ebfcbd1d72d9d496ce438cc08099b5d0416b932875704be2d0b4b28d0a')

build() {
  cd rich-${pkgver}
  poetry build --format wheel
}

package() {
  cd rich-${pkgver}
  export PYTHONHASHSEED=0
  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" --ignore-installed --no-deps dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
