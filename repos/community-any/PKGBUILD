# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=8.10.0
pkgrel=1
pkgdesc='Enhanced Interactive Python shell'
arch=('any')
url=https://ipython.org
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline' 'python-stack-data')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
# texlive-bin checkdep excluded due to test_latex_to_png_color failure
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy' 'python-trio'
              'python-matplotlib' 'python-curio' 'python-pandas' 'tcsh')
optdepends=('python-black: to auto format with Black'
            'yapf: to auto format with YAPF')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "IPython-icon.png::https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('b13a1d6c1f5818bd388db53b7107d17454129a70de2b87481d555daede5eb49e'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('8ca8781326396ffa1e8012bab3b539b857a68e212afd5b2b97bc2f0eac6ec1aee45c0743d745554ef24fabd24667c2d6cdb3927350ca61b747e02afa215c1519'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $pkgname-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  # FS#47046
  install -Dm644 IPython-icon.png "$pkgdir"/usr/share/pixmaps/ipython.png

  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  cd 'examples/IPython Kernel'
  # FS#45120
  sed -i 's/gnome-netstatus-idle/ipython/' ipython.desktop
  install -Dm644 -t "$pkgdir"/usr/share/applications ipython.desktop

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$pkgname-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
