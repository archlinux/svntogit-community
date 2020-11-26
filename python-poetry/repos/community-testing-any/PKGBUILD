# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>

_pkgname=poetry
pkgname=python-poetry
pkgver=1.0.10
pkgrel=3
pkgdesc="Python dependency management and packaging made easy"
arch=('any')
url="https://poetry.eustace.io/"
license=('MIT')
_deps=('cachecontrol' 'cachy' 'cleo' 'html5lib' 'jsonschema' 'lockfile'
       'pkginfo' 'pyparsing' 'pyrsistent' 'requests' 'requests-toolbelt'
       'shellingham' 'tomlkit' 'keyring' 'pexpect')
depends=("${_deps[@]/#/python-}")
makedepends=('python-dephell')
checkdepends=('git' 'python-pytest' 'python-pytest-mock' 'python-httpretty')
provides=('poetry')
conflicts=('poetry')
replaces=('poetry')
source=("${_pkgname}-${pkgver}.tar.gz::https://github.com/sdispater/${_pkgname}/archive/${pkgver}.tar.gz"
        "0001-Suppress-dependency-versions-which-are-known-to-be-t.patch"
        "poetry-completions-generator")
sha256sums=('fc6d236cca39c73e66f7467e875a02191fd0664303eff88b3723ab41508cad7c'
            '14362e48099d14530905fe7b65650c7e074bfe10f05fffa516b0d0e095df16a8'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6')
b2sums=('ffac88837810cc49687530fe8448335806182cdf04ac5a34c610e279c295159f0883f66994f4aa3731dbb5ebaf54bcb2993779738e086747676e3c4ba2859d87'
        '241da60804f7c9a486c3d57efe1984345fa93b697d78d494f1f339fbe27c30e072e853c12cf5def124bfccc42dcc34daa6d393f9c41284352f541956103facce'
        '3fd62e7936d7547dcd06a1a7519f176a1597553ecc959144a4be799bb7e2d688e187f14604d3e359ed10c128c722ebd588c07ca318e0be0a31d276dcb388e2e1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # fix various overly restrictive version pinning
    patch -p1 -i ../0001-Suppress-dependency-versions-which-are-known-to-be-t.patch

    dephell deps convert --from pyproject.toml --to setup.py
}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # only works inside git repositories
    pytest \
        -k 'not test_default_with_excluded_data ' \
        --ignore tests/console/commands/test_add.py \
        --ignore tests/console/commands/test_export.py \
        --ignore tests/console/commands/test_show.py \
        --deselect tests/packages/test_locker.py::test_lock_file_data_is_ordered \
        --deselect tests/packages/test_locker.py::test_lock_packages_with_null_description \
        --deselect tests/packages/test_locker.py::test_lock_file_should_not_have_mixed_types \
        --deselect tests/packages/test_locker.py::test_locking_legacy_repository_package_should_include_source_section
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

    # install completions, which for some crazy reason hardcode the filename
    # used to invoke which is __main__.py if we use python -m poetry, and also
    # adds the full directory path???
    install -m755 "${srcdir}"/poetry-completions-generator ./poetry-completions-generator
    ./poetry-completions-generator completions bash | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/bash-completion/completions/poetry
    ./poetry-completions-generator completions zsh | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/zsh/site-functions/_poetry
    ./poetry-completions-generator completions fish | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/fish/vendor_completions.d/poetry.fish
}
