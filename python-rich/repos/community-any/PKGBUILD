# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Hao Long <imlonghao@archlinuxcn.org>

pkgname=python-rich
pkgver=13.0.0
pkgrel=1
pkgdesc='Render rich text, tables, progress bars, syntax highlighting, markdown and more to the terminal'
arch=(any)
url='https://github.com/willmcgugan/rich'
license=('MIT')
depends=(python-{colorama,commonmark,pygments})
makedepends=(python-{build,installer,poetry-core,wheel})
source=("https://github.com/willmcgugan/rich/archive/v${pkgver}/rich-${pkgver}.tar.gz")
b2sums=('b2b323b633e6600dd1595c1769daf3659b2d7cf6f98fe91ca9e083c24bc3de9de79b27de08144ab7acaa3634cc588f1548d73536555a06f1b4832f91c978ab9a')

build() {
  cd rich-${pkgver}
  python -m build --wheel --no-isolation
}

package() {
  cd rich-${pkgver}
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
