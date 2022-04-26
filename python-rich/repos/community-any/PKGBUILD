# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=12.3.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=('python-colorama' 'python-pygments' 'python-typing_extensions' 'python-commonmark')
makedepends=('python-pip' 'python-poetry')
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('baa098e25768b4b84a269547c7726d281f67e333c0993513223dfdda7023001ea78b6edd10218726ae888e7216e18c6c4d5b9711268d083dfd0a41c3162658c9')

build() {
  cd rich-${pkgver}
  poetry build --format wheel
}

package() {
  cd rich-${pkgver}
  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" --ignore-installed --no-deps dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
